PROJECT_NAME="sfml-snake"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

if [[ $1 == "comp" ]]
then
  mkdir -p build
  rm -f build/*
  g++ -c src/Main.cpp src/Classes/*.cpp
  g++ *.o -o build/$PROJECT_NAME -I src/Headers $LIBRARIES
  rm *.o
elif [[ $1 == "comph" ]]
then
  g++ --std=c++11 src/Headers.h
elif [[ $1 == "cc" ]]
then
  > src/Headers/${2^}.h
  > src/Classes/${2^}.cpp

  echo "#ifndef ${2^^}_H" >> src/Headers/${2^}.h
  echo "#define ${2^^}_H" >> src/Headers/${2^}.h
  echo "" >> src/Headers/${2^}.h
  echo "class ${2^}" >> src/Headers/${2^}.h
  echo "{" >> src/Headers/${2^}.h
  echo "  public:" >> src/Headers/${2^}.h
  echo "    // Constructor and Destructor" >> src/Headers/${2^}.h
  echo "    ${2^}();" >> src/Headers/${2^}.h
  echo "    virtual ~${2^}();" >> src/Headers/${2^}.h
  echo "};" >> src/Headers/${2^}.h
  echo "" >> src/Headers/${2^}.h
  echo "#endif // ${2^^}_H" >> src/Headers/${2^}.h

  echo "#include \"../Headers/${2^}.h\"" >> src/Classes/${2^}.cpp
  echo "" >> src/Classes/${2^}.cpp
  echo "// Constructor and Destructor" >> src/Classes/${2^}.cpp
  echo "" >> src/Classes/${2^}.cpp
  echo "${2^}::${2^}()" >> src/Classes/${2^}.cpp
  echo "{" >> src/Classes/${2^}.cpp
  echo "" >> src/Classes/${2^}.cpp
  echo "}" >> src/Classes/${2^}.cpp
  echo "" >> src/Classes/${2^}.cpp
  echo "${2^}::~${2^}()" >> src/Classes/${2^}.cpp
  echo "{" >> src/Classes/${2^}.cpp
  echo "" >> src/Classes/${2^}.cpp
  echo "}" >> src/Classes/${2^}.cpp
elif [[ $1 == "rc" ]]
then
  rm src/Headers/${2^}.h
  rm src/Classes/${2^}.cpp
elif [[ $1 == "run" ]]
then
  ./build/$PROJECT_NAME
else
  echo "No option provided!"
fi
