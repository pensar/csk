// author : Mauricio Gomes
// license: MIT (https://opensource.org/licenses/MIT)

#include <iostream>
#include "../cpplib/io_util.hpp"
#include "../cpplib/s.hpp"
// author : Mauricio Gomes
// license: MIT (https://opensource.org/licenses/MIT)


namespace pensar_digital
{
    namespace csk
    {
        using namespace std;
        using namespace pensar_digital::cpplib;

        void line_handler (const int64_t line_number, const S& line)
        {
            for(S::size_type i=0; i < line.length(); i++)
            {
                S::value_type ch = line[i];
                if (ch != W('\n'))
                {

                }

            }
        }
    }
}

int main()
{
    namespace pd = pensar_digital;

    pensar_digital::cpplib::read_file ("c:\\mg\\prj\\csk\\doc\\csk_syntax_examples.csk", pd::csk::line_handler);
    return 0;
}
