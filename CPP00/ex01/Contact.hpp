#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    public:
            Contact(){}; //Constructor para inicializar, aunque este no hace nada
            std::string retName(void);
            std::string retLastName(void);
            std::string retNickname(void);
            std::string retPhoneNumber(void);
            std::string retSecret(void);
            
            void setName(std::string name);
            void setLastName(std::string last_name);
            void setNickname(std::string nickname);
            void setPhoneNumber(std::string PhoneNum);
            void setSecret(std::string secret);
    private:
            std::string p_name;
            std::string p_lastname;
            std::string p_nickname;
            std::string p_phone_number;
            std::string p_secret;
};

#endif