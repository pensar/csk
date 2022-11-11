#ifndef CSKPROGRAM_HPP
#define CSKPROGRAM_HPP

#include "object.hpp"
#include <list>

namespace pensar_digital
{
    namespace csk
    {
        class CSKObject: Object
        {
            public:
                std::string get_name (                         ) const {return name; };
                void        set_name (const std::string&  aname)       {name = aname;};

            private:
                std::string name;
        }

        class Type: CSKObject
        {

        }

        class Parameter: Object
        {
            public:
                Parameter() {};
                Parameter(Type atype; std::string aname): type(atype), name(aname) {};
            private:
                Type type;
                std::string name;
        }

        class Parameters
        {
            private:
                std::list<Parameter> params;
        }

        class Method
        {
            Method () {};
            Method (Type: areturn_type, std::string aname, Parameters: aparams): return_type (areturn_type), name(aname), params(aparams) {};
            private:
                Type return_type;
                std::string name;
                Parameters: params;
        }

        class CSKProgram : public Object
        {
            using Methods = std::list<Method>;
            public:
                /** Default constructor */
                CSKProgram(): private_methods(), protected_methods(), public_methods() {};

                /** Default destructor */
                virtual ~CSKProgram();
                /** Copy constructor
                 *  \param other Object to copy from
                 */

                CSKProgram(const CSKProgram& other);
                /** Assignment operator
                 *  \param other Object to assign from
                 *  \return A reference to this
                 */

                CSKProgram& operator=(const CSKProgram& other);

            protected:

            private:
                Methods private_mthods;
                Methods protected_methods;
                Methods public_methods;
        };
    }
}

#endif // CSKPROGRAM_HPP
