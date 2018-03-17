# Object-detection
## Wine bottle detection
### Usage
First you need to open `codes/CMakeLists.txt` file and change the directory in the `include()` to your `dlib/cmake` directory.  For example:  
`include(../dlib/cmake)`

If you don't have dlib you can download from [here](https://github.com/davisking/dlib)

To run the program, you should change your directory to `codes/build` in terminal and use commands below:  
`$cmake ..`   
`$make`    
`$./wine_object_detection sp.dat ../../testing/*.jpg`  

Result will be saved in "saved_images" folder

If you want train it again you can use  
`$./fhog_object_detector_ex`  
If you want to predict the shape again you can use  
`$./train_shape_detector`
