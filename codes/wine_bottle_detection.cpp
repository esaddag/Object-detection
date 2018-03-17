#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <dlib/image_processing/scan_image_pyramid_abstract.h>
#include <dlib/image_processing/scan_fhog_pyramid.h>
#include <dlib/image_processing/scan_image_custom.h>
#include <dlib/image_processing/scan_image_boxes_abstract.h>
#include <dlib/image_transforms.h>

using namespace dlib;
using namespace std;


int number=0;
int main(int argc, char** argv)
{  
    try
    {
        
        if (argc == 1)
        {
            cout << "Call this program like this:" << endl;
            cout << "./wine_bottle_detector sp.dat ../../testing/*.jpg" << endl;
            return 0;
        }
         typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;

         object_detector<image_scanner_type> detector;
       	 deserialize("object_detector.svm") >> detector;

       	 shape_predictor sp;
        deserialize(argv[1]) >> sp;

        image_window win;
        // Loop over all the images provided on the command line.
        for (int i = 2; i < argc; ++i)
        {
            cout << "processing image " << argv[i] << endl;
            array2d<rgb_pixel> img;
            load_image(img, argv[i]);
            // Make the image larger so we can detect small objects.
            pyramid_up(img);

            // Now tell the object detector to give us a list of bounding boxes
            // around all the objects in the image.
            std::vector<rectangle> dets = detector(img);
            cout << "Number of objects detected: " << dets.size() << endl;

            // Now we will go ask the shape_predictor to tell us the pose of
            // each object we detected.
            std::vector<full_object_detection> shapes;
            for (unsigned long j = 0; j < dets.size(); ++j)
            {
                full_object_detection shape = sp(img, dets[j]);
                cout << "number of parts: "<< shape.num_parts() << endl;
                cout << "pixel position of first part:  " << shape.part(0) << endl;
                cout << "pixel position of second part: " << shape.part(1) << endl;
              
                shapes.push_back(shape);
            }
            
            win.clear_overlay();
            for(int k=0;k<dets.size();k++){
                // Now let's view our object poses on the screen.
                for(int l=0;l<4;l++)
                    draw_solid_circle(img,shapes.at(k).part(l),5,rgb_pixel(255,0,0));

            draw_rectangle(img,dets[k],rgb_pixel(255,0,0),1);
            
            }
            
           win.set_image(img);
           save_jpeg(img,"../../saved_images/img"+to_string(number)+".jpg");
           
            number++;
          

  

            cout << "Hit enter to process the next image..." << endl;
            cin.get();
        }
    }
    catch (exception& e)
    {
        cout << "\nexception thrown!" << endl;
        cout << e.what() << endl;
    }
}