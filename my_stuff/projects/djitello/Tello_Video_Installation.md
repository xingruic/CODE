# How to Install Tello_Video
* Uses Python 2.7
* Uses Tello SDK

## Installing conda environment
Download [this file](https://raw.githubusercontent.com/NevGithub0823/CODE/master/my_stuff/projects/djitello/tello-video-conda-env.yml), then in `Anaconda PowerShell Prompt`:
``` powershell
conda env create -f tello-video-conda-env.yml
```

## Installing h264decoder
Download [https://github.com/DaWelter/h264decoder/archive/refs/tags/v1.zip](https://github.com/DaWelter/h264decoder/archive/refs/tags/v1.zip) and extract to folder `.\h264decoder\`, then in PowerShell:
``` powershell
cd h264decoder
python setup.py build_ext --cmake-args="-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
pip install -e .
```
Use forward slashes in `-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`.
Backslashes don't work, and Windows will also accept forward slashes.

## Installing Tello_Video
``` powershell
git clone https://github.com/dji-sdk/Tello-Python.git
cd .\Tello-Python\Tello_Video
```
Run the `install/Windows/install.bat` batch script

## Finishing up
The official repository uses the wrong module name for the decoder (at least when I'm writing this, [look here](https://github.com/dji-sdk/Tello-Python/tree/4d984874d6cf29e0d7cc76283b339b147c4a9095/Tello_Video)) so we have to change it.
First open the file we need to change:
``` powershell
notepad.exe /path/to/Tello_Video/tello.py
```
Then, at the top of the file, change `import libh264decoder` to `import h264decoder as libh264decoder`.

## Running Tello_Video
* Make sure you are connected to the TELLO_XXX wifi.
* In PowerShell:
	``` powershell
	python main.py
	```
* A window should pop up, showing the video stream from tello. Other functionaity is pretty self-explanatory.