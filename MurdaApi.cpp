#include <iostream>
#include <fstream>
#include <chrono>
#include <thread> 


int amountOfClasses = 1;
bool needsToBeUpdated = true;

/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107

std::cout << "\033[32m" << "Error!" << "\033[0m" << std::endl;
*/



class Main 
{
  private:
    bool nothing = NULL;
  public:
    bool updated = false;
    bool attatched = false;
    bool injected = false;

    int y = 0;
    Main() {
      std::cout << "Created New Object in Class: Main" << std::endl;

      std::cout << "You now have " << amountOfClasses++ << " Classes" << std::endl;
  }
 
};

#define RED "\033[31m"
#define GRN "\033[32m"

std::string UpdateContent
{R"(
//update code here //must del old murda.cpp file
)"};


bool update() 
{
  Main vars;

  if(vars.updated == false) {
    
    std::ofstream NewDylib("MURDA.cpp");
    std::ofstream MurdaDylib("MURDA.dylib");
    
    
    NewDylib << UpdateContent;
    MurdaDylib << "NULL";

    NewDylib.close();
    MurdaDylib.close();
    vars.updated = true;
  }

  
  return vars.updated;
}

int inject() 
{
  Main mink;
  #if defined _WIN32
    system("cls");
    std::cout << RED << "INJECTING... DEVICE NOT SUPPORTED WINDOWS\n";
    while(true)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    } 
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::cout << RED << "INJECTING... DEVICE NOT SUPPORTED LINUX\n";
    while(true)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    } 
#elif defined (__APPLE__)
    system("clear");
    mink.attached = true;
    std::cout << GRN << "DEVICE SUPPORTED";
    std::cout << GRN << "INJECTING";

#endif
}





int main()
{
  Main main;
  if(needsToBeUpdated == true && main.updated == false) {
    update();
    main.updated = true;
    needsToBeUpdated = false;
    if(main.updated == false) {
      std::cout << RED << "FATAL ERROR DETECTED\n";
      std::cout << GRN << "RETRYING.";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << GRN << "RETRYING..";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << GRN << "RETRYING...";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      update();
    } else {
      std::cout << GRN << "UPDATE SUCCESSFUL\n";
    }
    
  } else if(main.updated == NULL) {
    std::cout << RED <<  "false or NULL (Does not need to be updated)";
  } else {
    std::cout << "Does not need to be updated";
  }
 
  inject();

  return 0;
}