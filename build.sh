#！/bin/bash

DIR=`pwd`
if [ -d build ]; then
  rm -rf build
fi

mkdir build

# BUILD_LIB=false
# BUILD_EXCUTABLE=false

# for i in "$@"; do
#   if [ "$i" = "-l" ]; then
#     BUILD_LIB=true
#   elif [ "$i" = "-e" ]; then
#     BUILD_EXCUTABLE=true
#   fi
# done

# if [ $BUILD_LIB = true ]; then
#   CMAKE_COMMAND=-DBUILD_LIB:BOOL=${BUILD_LIB}
# else
#   CMAKE_COMMAND=-DBUILD_EXCUTABLE:BOOL=${BUILD_EXCUTABLE}
# fi


cd build
# cmake .. ${CMAKE_COMMAND}
cmake .. 
make -j4
echo "Build Done"


cd $DIR
cp -r ./include build/output

