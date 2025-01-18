//  Created by Семён Шестаков on 18.01.2025.

#ifndef LogUtils_hpp
#define LogUtils_hpp

#include <iostream>


#define _LOG_LEVEL 20


#define __LOG_FORMAT(format, ...)                                   \
    printf(format, ##__VA_ARGS__);                                  \
    std::cout << "\t\t" << __FILE__ << __LINE__ <<std::endl;


#if _LOG_LEVEL < 10
#define LOG_DEBUG(format, ...)                                      \
    std::cout << "[DEBUG]\t\t";                                     \
    __LOG_FORMAT(format, ##__VA_ARGS__);

#else
#define LOG_DEBUG(format, ...)

#endif


#define LOG_INFO(format, ...)                                       \
    std::cout << "[INFO]\t\t";                                      \
    __LOG_FORMAT(format, ##__VA_ARGS__);
    


#endif /* LogUtils_hpp */
