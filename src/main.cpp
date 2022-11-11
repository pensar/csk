#include <iostream>
#include "io_util.hpp"

namespace pd = pensar_digital;

namespace pensar_digital
{
    namespace csk
    {
        using namespace std;


        void line_handler (const int64_t line_number, const string& line)
        {
            for(string::size_type i=0; i < line.length(); i++)
            {
                string::value_type ch = line[i];
                if (ch != '\n')
                {

                }

            }
        }
    }
}

int main()
{
    pensar_digital::cpplib::read_file ("c:\\mg\\prj\\csk\\doc\\csk_syntax_examples.csk", pd::csk::line_handler);
    return 0;
}
