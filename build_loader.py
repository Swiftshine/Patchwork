import os
import shutil
import subprocess
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

def make_build_dir():
    if not os.path.exists("build"):
        os.makedirs("build/obj/")

COMPILER = get_dependency_path("deps/CodeWarrior/mwcceppc.exe", "CodeWarrior compiler")
KAMEK = get_dependency_path("deps/Kamek/Kamek.exe", "Kamek linker")
SYMBOLS = get_dependency_path("deps/symbols/", "Symbols folder")

def build(region: str):


    # Set up command strings
    compile_commands = list()
    compile_commands.append(f"{COMPILER} -i . -I- -i include/ -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -o build/obj/loader.o src/loader/loader.cpp")
    compile_commands.append(f"{COMPILER} -i . -I- -i include/ -Cpp_exceptions off -enum int -Os -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -o build/obj/rk5_loader.o src/loader/rk5_loader.cpp")

    kamek_command = f"{KAMEK} build/obj/loader.o build/obj/rk5_loader.o -static=0x80001900 -output-code=build/loader.bin -output-riiv=build/RK5_{region}_loader.xml"

    # Compile code for target region
    print(f"Building target {region}...\n")
    
    #f os.path.exists(f"deps/dols/RK5_{region}.dol"):
    #    kamek_command += f" -input-dol=deps/dols/RK5_{region}.dol -output-dol=build/RK5_{region}_custom.dol"


    for command in compile_commands:
        if subprocess.call(command, shell=True) != 0:
            err("Compiling failed.")
    
    print("Compiling successful.\n")

    if subprocess.call(kamek_command, shell=True) != 0:
        err("Linking failed.")
    
    print("\nDone!")

# Main program

if __name__ == '__main__':
    print("RK5 loader build script\n")
    '''
    if len(sys.argv) < 2:
        print("Usage: ")
    ''' 

    make_build_dir()
    # Currently I'm only targeting USv1,
    # so until I decide to support multiple regions,
    # it stays like this for now.
    build("USA")

