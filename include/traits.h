#ifndef __LIBBITSET_TRAITS_H__
#define __LIBBITSET_TRAITS_H__

#define DECLARE_TRAITS(base_, type_) template <> struct base_<type_>{typedef type_ type_name;};
namespace libbitset {

namespace traits{

template <typename T>
struct numeric {
};

DECLARE_TRAITS(numeric, char)
DECLARE_TRAITS(numeric, unsigned char)
DECLARE_TRAITS(numeric, short)
DECLARE_TRAITS(numeric, unsigned short)
DECLARE_TRAITS(numeric, int)
DECLARE_TRAITS(numeric, unsigned int)
DECLARE_TRAITS(numeric, long unsigned int)
DECLARE_TRAITS(numeric, long long int)
DECLARE_TRAITS(numeric, long long unsigned int)

};//namespace traits
};//namespace libbitset
#endif//__LIBBITSET_TRAITS_H__
