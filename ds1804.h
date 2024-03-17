// @File		DS1804.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		17/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef DS1804_H
#define DS1804_H

#define DS1804_INC PORTCbits.RC0 
#define DS1804_UD PORTCbits.RC1 
#define DS1804_CS PORTCbits.RC3 

#define DS1804_INC_TRIS TRISCbits.RC0 
#define DS1804_UD_TRIS TRISCbits.RC1 
#define DS1804_CS_TRIS TRISCbits.RC3 

void DS1804_Write(unsigned char count, unsigned char ud)
{
    DS1804_CS = 0;
    
    for(unsigned int i = 0; i < count; i++)
    {
        DS1804_UD = ud;
            
         __asm__ __volatile__("nop");
         DS1804_INC = 0;
         __asm__ __volatile__("nop");
         DS1804_INC = 1;
         __asm__ __volatile__("nop");  
    }
    
    DS1804_CS = 1;  
    
    DS1804_INC = 0;
}

void DS1804_Init(void)
{
    DS1804_INC_TRIS = 0;
    DS1804_UD_TRIS = 0;
    DS1804_CS_TRIS = 0;
    
    DS1804_INC = 0;
    DS1804_CS = 1;
}

#endif 
