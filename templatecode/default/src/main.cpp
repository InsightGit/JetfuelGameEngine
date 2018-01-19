#include <jetfuelinspire.h>

int main(){
    jetfuel::inspire::Python_module_loader sayhello("hellohandler","sayhello",
                                                    "Scripts");
    bool executedstatus;
    std::string error;

	  sayhello.Execute(&executedstatus,&error, nullptr);

    if(!executedstatus){
        std::cerr << "Python Interpreter ERROR! Error is:" <<
                      error << "\n";
        return 1;
    }
}
