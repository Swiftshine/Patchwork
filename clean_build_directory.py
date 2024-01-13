import os
import shutil

if __name__ == '__main__':

    if os.path.exists("build"):
        shutil.rmtree("build", ignore_errors=True)
        os.makedirs("build", exist_ok=True)
        print("Cleaned build directory.")
