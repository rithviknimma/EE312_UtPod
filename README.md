# EE312_UtPod
Project for EE312
To compile, run:
g++ -o UtPod Song.cpp UtPod.cpp UtPodDriver.cpp


1) log in to puTTy with username and password

2) once you are logged in, change directory that zipped UtPod file is in by doing the following (ex):

        cd EE312 (press enter)
        cd UtPod (press enter)


3) next, show that you have correct file at your location

        pwd (will show all files)

        - you should see prog05_civ298.zip in red
    3b) Create a folder by typing:

        mkdir folderName

    3c) Next, unzip the zipped project into this folder by typing:

        unzip prog05_civ298.zip -d folderName

    3d) Enter the folder you have created and extracted to by typing:

        cd folderName

4) Once you have unzipped and are in the folder of the project,
    type:

    make

    -this compiles the files to be able to run them at a later time

5) Once this is done, you are ready to run. Type in:

    ./test (press enter)





