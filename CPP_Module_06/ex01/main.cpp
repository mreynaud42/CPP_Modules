/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:16:46 by mreynaud          #+#    #+#             */
/*   Updated: 2025/04/11 12:51:27 by mreynaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42424;
    std::cout << "value: " << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "uintptr_t:\t" << (void *)raw << "\t" << raw << std::endl;

    Data* new_data = Serializer::deserialize(raw);
    std::cout << "Data*:\t\t" << new_data << "\t" << (unsigned long)new_data << std::endl;
    std::cout << "value: " << new_data->value << std::endl;

    return 0;
}
