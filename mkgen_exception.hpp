#include <string>
#include <exception>


class mkgen_exception  : std::exception{

    private:
        std::string reason;
    public:
        explicit mkgen_exception(std::string r){
            reason = r;
        }
        const char* what() const noexcept{
            return reason.c_str();
        }

};