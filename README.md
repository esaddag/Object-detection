# Object-detection
## Wine bottle detection
### USAGE
To run the program, in "codes/build" directory you should use commands below:
`$cmake .. $make $./wine_object_detection sp.dat ../../testing/*.jpg`

Result will be saved in "saved_images" folder

If you want train it again you can use
`$./fhog_object_detector_ex`
If you want to predict the shape again you can use
`$./train_shape_detector`
