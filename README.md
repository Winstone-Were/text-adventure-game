
# C++ Text Adventure Game

## The Game story is directed by a story.json file placed in the build directory
### The build directory is where the executable is placed after running 
```make 
```

### sample story.json

```
{
    "start": {
        "story-line": "In the year 2040, you are a renowned investor exploring new opportunities in futuristic technologies. Do you start by investing in Space Travel or Renewable Energy?",
        "choices": [
            "Space Travel",
            "Renewable Energy"
        ],
        "next": [
            "space_travel",
            "renewable_energy"
        ]
    },
    "space_travel": {
        "story-line": "You chose to invest in Space Travel. Your first meeting is with a startup developing faster-than-light travel. Do you agree to fund their research or look for more established companies?",
        "choices": [
            "Fund research",
            "Look for established companies"
        ],
        "next": [
            "fund_research",
            "established_companies"
        ]
    }
}
```


## Clone the repo:

```
    git clone https://github.com/Winstone-Were/TextAdventureGame
```

## Download the json.hpp file:
```
    mkdir -p include/nlohmann
    wget https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp -O include/nlohmann/json.hpp
```

## Build The Project

### Create a build directory
```
mkdir build
cd build
```

### Run cmake to generate build files

```
cmake ..
```

### Build the project
```
make
```

### Run the executable 

#### on linux

```
./TextAdventureGame
```

#### on Windows

```
TextAdventureGame
```

