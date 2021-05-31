# How to Install Tello_Video
* Uses Python 2.7
* Uses Tello SDK

## Installing conda environment
``` powershell
conda create -n tello-video python=2.7.18 opencv=3.2.0=np113py27_204 pillow=6.2.1=py27h5b88493_0 boost=1.70.0=py27ha6300db_0
conda activate tello-video
```

## Installing h264decoder
Download [https://github.com/DaWelter/h264decoder/archive/refs/tags/v2.zip](https://github.com/DaWelter/h264decoder/archive/refs/tags/v2.zip) and extract to folder `.\h264decoder\`, then:
``` powershell
cd h264decoder
python setup.py build_ext --cmake-args="-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
pip install -e .
```
Use forward slashes in `-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`.

## Installing Tello_Video
``` powershell
git clone https://github.com/dji-sdk/Tello-Python.git
git reset -hard 4d984874d6cf29e0d7cc76283b339b147c4a9095
cd .\Tello-Python\Tello_Video
```
Run the `install/Windows/install.bat` batch script.
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
* A window should pop up, showing the video stream from tello.