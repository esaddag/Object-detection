cmake_minimum_required(VERSION 2.8.12)
PROJECT(examples)
include(../dlib/cmake)

MACRO(add_example name)
   ADD_EXECUTABLE(${name} ${name}.cpp)
   TARGET_LINK_LIBRARIES(${name} dlib::dlib )
ENDMACRO()

MACRO(add_gui_example name)
   if (DLIB_NO_GUI_SUPPORT)
      message("No GUI support, so we won't build the ${name} example.")
   else()
      add_example(${name})
   endif()
ENDMACRO()

add_gui_example(wine_bottle_detection)
add_gui_example(fhog_object_detector_ex)
add_example(train_shape_predictor_ex)





