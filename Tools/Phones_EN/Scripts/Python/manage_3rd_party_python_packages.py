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
    boilerplate_comment = """
    If an Error occurs during installation,
    you may try installing packages individually

   ``` bash
    # Installing ffmpeg: Option 1 (Windows)
    $ pip install ffmpeg-python

    # Installing ffmpeg: Option 2 (Windows)
    $ choco install ffmpeg-python

    # Installing ffmpeg (Linux)
    $ sudo apt update && sudo apt install ffmpeg-python
    ```

    ```bash
    $ pip install numpy
    $ pip install scipy
    $ pip install matplotlib
    $ pip install wave
    $ pip install pydub
    $ pip install torch
    $ pip install torchaudio
    $ pip install torchvision
    ```

    ```bash
    Optional: Install librosa in lieu of torchaudio for audio processing
    $ pip install librosa
    ```
    """
    packages = ["wave", "ffmpeg-python", "numpy", "scipy", "matplotlib", "pydub", "torch","torchaudio", "torchvision"]
    # manage_packages("install", packages)
    # manage_packages("uninstall", packages)
    # manage_packages("upgrade", packages)
