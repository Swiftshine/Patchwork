import glob
import shutil
import subprocess
import os
import sys
from pathlib import Path

def err(message: str):
    print(f"Error: {message}")
    sys.exit(1)

def get_dependency_path(path, name):
    path = Path(path)
    if not os.path.exists(path):
        err(f"{name} not found!")
    return path

COMPILER = get_dependency_path("deps/CodeWarrior/mwcceppc.exe", "CodeWarrior compiler")
COMPILER_ASM = get_dependency_path("deps/CodeWarrior/mwasmeppc.exe", "CodeWarrior assembler")
KAMEK = get_dependency_path("deps/Kamek/Kamek.exe", "Kamek linker")

# Main program

if __name__ == '__main__':
    region = "USA"

    # Check if CodeWarrior and Kamek are present
    if not os.path.exists(COMPILER):
        err("CodeWarrior compiler not found.")
    if not os.path.exists(KAMEK):
        err("Kamek linker not found.")

    compile_command = f"{COMPILER} -i . -I- -i include/ -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -o"
    asm_compile_command = f"{COMPILER_ASM} -i . -I- -i include/ -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -S -o"

    # Clean build/obj directory
    #if os.path.exists("build/obj"):
    #    shutil.rmtree("build/obj", ignore_errors=True)
    
    # Get all C++ source files that might need to be compiled
    tasks = list()
    asm_tasks = list()

    for root, dirs, files in os.walk("src"):
        for file in files:
            if file.endswith(".cpp"):
                # ignore loader files
                if file == "loader.cpp" or file == "rk5_loader.cpp":
                    continue
                source_path = os.path.join(root, file)
                build_path = source_path.replace("src", "build/obj/").replace(".cpp", ".o")

                os.makedirs(os.path.dirname(build_path), exist_ok=True)

                tasks.append((source_path, build_path))
            elif file.endswith(".s"):
                source_path = os.path.join(root, file)
                build_path = source_path.replace("src", "build/obj/").replace(".s", ".o")

                os.makedirs(os.path.dirname(build_path), exist_ok=True)

                asm_tasks.append((source_path, build_path))
    if len(tasks) < 1:
        err("No source files found.")
    
    # Process all compile tasks

    for task in tasks:
        source_path, build_path = task

        print(f"Compiling {source_path}...")

        if subprocess.call(f"{compile_command} {build_path} {source_path}", shell=True) != 0:
            err("Compiler error.")
    
    for asm_task in asm_tasks:
        source_path, build_path = asm_task

        print(f"Assembling {source_path}...")

        if subprocess.call(f"{asm_compile_command} {build_path} {source_path}", shell=True) != 0:
            err("Assembler error.")

    print("\nCompilation successful.")
    # Link all object files
    print("\nLinking...")

    object_files = " ".join([task[1] for task in tasks])
    asm_object_files = " ".join([asm_task[1] for asm_task in asm_tasks])

    kamek_command = f"{KAMEK} {object_files} {asm_object_files} -static=0x80001900 -externals=symbols/{region}.txt -output-kamek=build/RK5_{region}.bin"

    if subprocess.call(kamek_command, shell=True) != 0:
        err("Linking failed.")

    # Remove useless "d" files
    for file in glob.glob("build/*.d"):
        os.remove(file)

    print("\nDone!")
