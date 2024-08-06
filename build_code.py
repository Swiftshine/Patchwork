import subprocess
import os
import sys
from pathlib import Path
import yaml
import colorama
from colorama import Fore, Style
colorama.init()

def err(message: str):
    print(Fore.RED + f"Error: {message}" + Style.RESET_ALL)
    sys.exit(1)

def warn(message: str):
    print(Fore.YELLOW + f"Warning: {message}" + Style.RESET_ALL)
    
def info(message: str):
    print("\n" + Fore.CYAN + f"Info: {message}" + Style.RESET_ALL)

def debug(message: str):
    print(Fore.YELLOW + Style.BRIGHT + f"Debug: {message}" + Style.RESET_ALL)

def get_dependency_path(path, name):
    path = Path(path)
    if not os.path.exists(path):
        err(f"{name} not found!")
    return path

COMPILER = get_dependency_path("deps/CodeWarrior/mwcceppc.exe", "CodeWarrior compiler")
COMPILER_ASM = get_dependency_path("deps/CodeWarrior/mwasmeppc.exe", "CodeWarrior assembler")
KAMEK = get_dependency_path("deps/Kamek/Kamek.exe", "Kamek linker")

def get_cpp_tasks(target: str):
    result = list()
    if target != "all":
        target_files = list()

        # Go through the yaml and include every C++ source
        
        with open("modules/" + target, 'r') as file:
            sources = list()
            yaml_file = yaml.safe_load(file)

            if "CPP" in yaml_file:
                sources = yaml_file['CPP']
            else:
                return None
            
            if sources is None:
                return None

            sources = yaml_file['CPP']
            for source in sources:
                if not os.path.exists(source):
                    warn(source + " doesn't exist! Skipping it.")
                    continue
                source_name = source.replace("src/", "").replace(".cpp", "")
                result.append(("src/" + source_name + ".cpp", "build/obj/" + source_name + ".o"))

    elif target == "all":
        for root, dirs, files in os.walk("src"):
            for file in files:
                if file.endswith(".cpp"):
                    # ignore loader files
                    if file == "loader.cpp" or file == "rk5_loader.cpp":
                        continue
                    source_path = os.path.join(root, file)
                    build_path = source_path.replace("src", "build/obj").replace(".cpp", ".o")

                    os.makedirs(os.path.dirname(build_path), exist_ok=True)

                    result.append((source_path, build_path))
    return result

def get_asm_tasks(target: str):
    result = list()

    if target != "all":
        target_files = list()

        # Go through the yaml and include every ASM source

        with open("modules/" + target, 'r') as file:
            yaml_file = yaml.safe_load(file)

            sources = list()

            if "ASM" in yaml_file:
                sources = yaml_file['ASM']
            else:
                return None
            
            if sources is None:
                return None

            for source in sources:
                source_name = source.replace("src/", "")
                if source_name.endswith(".s"):
                    if not os.path.exists(source):
                        warn(source + " doesn't exist! Skipping it.")
                        continue
                    source_name = source_name.replace(".s", "")
                    result.append(("src/" + source_name + ".s", "build/obj/" + source_name + ".o"))
                elif source_name.endswith(".S"):
                    if not os.path.exists(source):
                        warn(source + " doesn't exist! Skipping it.")
                        continue
                    source_name = source_name.replace(".S", "")
                    result.append(("src/" + source_name + ".S", "build/obj/" + source_name + ".o"))
    elif target == "all":
        for root, dirs, files in os.walk("src"):
            for file in files:
                if file.endswith(".s") or file.endswith(".S"):
                    source_path = os.path.join(root, file)
                    if file.endswith(".s"):
                        build_path = source_path.replace("src", "build/obj").replace(".s", ".o")
                    elif file.endswith(".S"):
                        build_path = source_path.replace("src", "build/obj").replace(".S", ".o")

                    os.makedirs(os.path.dirname(build_path), exist_ok=True)

                    result.append((source_path, build_path))

    return result
# Main program

if __name__ == '__main__':
    # Check arguments
    arg_count = len(sys.argv) - 1
    if arg_count > 1:
        print("Usage:   " + os.path.basename(sys.argv[0]) + " <yaml filename>")
        print("Example: " + os.path.basename(sys.argv[0]) + " custom_module.yaml")
        sys.exit(1)
    
    # Begin
    print("-- RK5 code build script --")

    # Check module target
    module_target = ""
    if arg_count == 1: # user specified a yaml file
        module_target = sys.argv[1]
        if not module_target.endswith(".yaml"):
            module_target += ".yaml"
        
        if not os.path.exists("modules/" + module_target): # the user-specified yaml doesn't actually exist
            warn(module_target + " does not exist in the 'modules' folder")
            module_target = "all"

    else: # user did not specify a yaml file
        module_target = "all"

    print("Building target: " + Fore.CYAN + module_target + Style.RESET_ALL)

    # might support more versions in the future
    region = "USA"

    # Check if CodeWarrior and Kamek are present
    if not os.path.exists(COMPILER):
        err("CodeWarrior compiler not found.")
    if not os.path.exists(KAMEK):
        err("Kamek linker not found.")

    compile_command = f"{COMPILER} -i . -I- -i include/ -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -o"
    asm_compile_command = f"{COMPILER_ASM} -i . -I- -i include/ -c -o"

    # Get all source files that might need to be compiled
    cpp_tasks = get_cpp_tasks(module_target)
    asm_tasks = get_asm_tasks(module_target)
    
    if cpp_tasks is None and asm_tasks is None:
        err(f"No source files found in target {module_target}.")
    
    # Process all compile tasks

    if cpp_tasks is not None and len(cpp_tasks) > 0:
        info("Compiling...")
        for task in cpp_tasks:
            source_path, build_path = task

            print(f"Compiling {source_path}...")

            if subprocess.call(f"{compile_command} {build_path} {source_path}", shell=True) != 0:
                err("Compiler error.")
    
    if asm_tasks is not None and len(asm_tasks) > 0:
        info("Assembling...")
        for asm_task in asm_tasks:
            source_path, build_path = asm_task

            print(f"Assembling {source_path}...")

            if subprocess.call(f"{asm_compile_command} {build_path} {source_path}", shell=True) != 0:
                err("Assembler error.")
    
    # Link all object files
    info("Linking...")

    cpp_object_files = ""
    if cpp_tasks is not None:
        cpp_object_files = " ".join([task[1] for task in cpp_tasks])

    asm_object_files = ""
    if asm_tasks is not None:
        asm_object_files = " ".join([asm_task[1] for asm_task in asm_tasks])

    kamek_command = f"{KAMEK} {cpp_object_files} {asm_object_files} -externals=symbols/{region}.txt -output-kamek=build/RK5_{region}.bin"

    if subprocess.call(kamek_command, shell=True) != 0:
        err("Linking failed.")

    print(Fore.GREEN + "\nDone!" + Style.RESET_ALL)
