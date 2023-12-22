import subprocess
import os

current_directory = os.getcwd()

subprocess.run(["git", "fetch", "https://github.com/Manmadeeers/KOISoftware"], cwd=current_directory)
subprocess.run(["git", "pull"], cwd=current_directory)