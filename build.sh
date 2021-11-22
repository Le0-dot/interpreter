rm -rf ./cmake

if [ $# -eq 1 ]; then
    if [ $1 = "-D" ]; then
	cmake . -B ./cmake -DCMAKE_BUILD_TYPE=Debug 
    elif [ $1 = "-R" ]; then
	cmake . -B ./cmake -DCMAKE_BUILD_TYPE=Relese
    fi
else
    cmake . -B ./cmake -DCMAKE_BUILD_TYPE=Relese
fi

cd cmake 
make
