#include <iostream>  

class myexception : public std::exception 
{  
    public:  

        const char* what() const throw () 
        {  
            std::cout << "my exception" << std::endl;  
            return NULL;
        }  
};  


void f1(bool flag = true) 
{  
    if (flag) throw myexception();  
}  

void f2(bool flag = true) throw () 
{  
    if (flag) throw myexception();  
} 



int main(void) 
{  
    try 
    {  
        f1();  
    } catch (...)
    {  
    }  
    std::cout << "f1()异常将被捕获,不会 abort,将继续执行" << std::endl;  

    try 
    {  
        f2();  
    } catch (...) 
    {  
    }  
    std::cout << "f2()异常不会被捕获,程序将会 abort,将不会执行该条语句" << std::endl;  

    return 0;  
}
