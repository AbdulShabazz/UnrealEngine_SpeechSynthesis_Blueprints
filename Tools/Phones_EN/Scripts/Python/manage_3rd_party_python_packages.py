import os
import platform
import subprocess

def is_admin():
    if platform.system() == "Windows":
        # Different approach for Windows
        import ctypes
        return ctypes.windll.shell32.IsUserAnAdmin() != 0
    else:
        return os.geteuid() == 0

def manage_packages(action, packages):
    if not is_admin():
        print("Administrative rights are required to perform this action.")
        return
    
    for package in packages:
        try:
            if action == "install":
                subprocess.run(["pip", "install", package], check=True)
            elif action == "uninstall":
                subprocess.run(["pip", "uninstall", "-y", package], check=True)
            elif action == "upgrade":
                subprocess.run(["pip", "install", "--upgrade", package], check=True)
        except subprocess.CalledProcessError:
            print(f"Failed to {action} {package}")

if __name__ == "__main__":
    packages = ["wave", "ffmpeg-python", "numpy", "scipy", "matplotlib", "pydub", "torch"]
   # manage_packages("install", packages)
    # manage_packages("uninstall", packages)
    # manage_packages("upgrade", packages)
