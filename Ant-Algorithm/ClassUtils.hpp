//  Created by Семён Шестаков on 16.09.2024.

#ifndef ClassUtils_hpp
#define ClassUtils_hpp

#define DELETE_COPY_AND_MOVE(ClassName) \
    ClassName(ClassName&& other) = delete; \
    ClassName(const ClassName& other) = delete; \
    ClassName& operator=(ClassName&& other) = delete; \
    ClassName& operator=(const ClassName& other) = delete;

#endif /* Utils_hpp */
