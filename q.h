/*******************************************************************************
\File test.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Containers, Iterators & Functors
\Par Programming Lab #10
\Date 24-03-2022

  \Brief
   This program will take in an std::array<T,N> to determine 

   1. If the numbers are prime, arrange all unique prime numbers in descending
      order into a container std::vector<unsigned> and returns said container
      to the main source file.

   2. The exponential of the array elements. The data will be stored in 
      std::map<T,T> the first T contains the key and the second, the associated
      data, in this case, the exponential of the key. Each key is unique. The 
      std::map<T,T> is then returned to the main source file.
*******************************************************************************/
#include <algorithm>
#include <array>
#include <vector>
#include <map>

namespace hlp2 {
    /**************************************************************************/
    /*!
        \brief
        This function determines if the numbers are prime. It then sorts all 
        unique prime numbers in descending order into a container 
        std::vector<unsigned> and returns said container to the main source 
        file.

        \param begin
        Iterator to the first element of the std::array<T,N>.

        \param end
        Iterator to the one past-the-end of the std::array<T,N>.

        \param is_prime
        Bool to inform as to whether the element is a prime number.

        \param vec
        The vector container of the prime numbers.

        \param f
        Unsigned variable used in the calculation to determine prime numbers.

        \param uni
        Iterator for duplicates.

        \return
        std::vector<unsigned> vec that contains the sorted unique prime numbers.
    */
    /**************************************************************************/
    template<typename It>
    std::vector<unsigned> prime(It begin, It end) {
        bool is_prime = true;
        std::vector<unsigned> vec;

        //Identify prime number
        for(unsigned f{2}; begin < end; ++begin) {
            if (*begin != 0 && *begin != 1) {  
                for(f = 2; f <= *begin/2; ++f) {
                    if (*begin % f == 0) {
                        is_prime = false;
                        break;
                    }
                    else    
                        is_prime = true;
                }
                if (is_prime == true)
                    vec.push_back(*begin);
            }
        }
        //Sorting
        std::sort(vec.rbegin(), vec.rend());
        std::vector<unsigned>::iterator uni;
        uni = std::unique(std::begin(vec), std::end(vec));
        vec.erase(uni, std::end(vec));
        return vec;
    }

    /**************************************************************************/
    /*!
        \brief
        This function determines the exponential of the array elements. The data
        will be stored in std::map<T,T> the first T contains the key and the 
        second, the associated data, in this case, the exponential of the key. 
        Each key is unique. The std::map<T,T> is then returned to the main 
        source file.

        \param lhs
        The const reference to the std::array<T,N>.

        \param power
        The unsigned const exponent for exponential calculation.

        \param result
        The map container of the key (unique orginal set) and expoential
        corresponding key.

        \param i
        Counter to look through each element of the array.

        \param exp
        The modifiable power.

        \param powerup
        Contains the expoential corresponding element.
        
        \return
        std::map<T, T> result container with the unique original set of array
        element values and the corresponding exponential values.
    */
    /**************************************************************************/
    template<typename T, size_t N>
    std::map<T,T> pow(std::array<T,N>const& lhs, unsigned const power){
        std::map<T, T> result;
        for (size_t i{}; i < lhs.size(); ++i) {
            if (power == 1) {
                result.insert( std::pair<T,T> (lhs[i], lhs[i]) );
            }
            else if (power == 0) {
                result.insert( std::pair<T,T> (lhs[i], 1) );
            }
            else {
                unsigned exp = power;
                --exp;
                T powerup{};
                for (powerup = lhs[i]; exp; --exp) {
                    powerup *= lhs[i];
                }
                result.insert( std::pair<T,T> (lhs[i], powerup) );
            }
        }
        return result;
    }
}