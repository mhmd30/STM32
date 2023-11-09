/* 
 * File:   application.c
 * Author: Mohammed_Elnefary 
 * Created on April 2, 2023, 5:25 PM
 */
#include "application.h"

uint8 counter = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    lcd_8bit_send_custom_char(&lcd_2 , 1 , 1 , zizo , 1);
    lcd_8bit_send_custom_char(&lcd_2 , 1 , 20 , killer , 2);
    
    while(1){
        lcd_8bit_send_char_data_pos(&lcd_2, 1 ,19 ,'-');
        lcd_8bit_send_char_data_pos(&lcd_2, 1 ,19 ,' ');
        for(counter = 19 ; counter > 1 ; counter--){
            lcd_8bit_send_char_data_pos(&lcd_2, 1 ,counter ,'-');
            __delay_ms(200);
            lcd_8bit_send_char_data_pos(&lcd_2, 1 ,counter ,' ');
        }
        __delay_ms(400);
        lcd_8bit_send_custom_char(&lcd_2 , 1 , 1 , zizo_dead , 1);
        __delay_ms(1000);
        lcd_4bit_send_command(&lcd_2 ,_LCD_CLEAR);
        __delay_ms(400);
        lcd_8bit_send_string_pos(&lcd_2 , 1 , 3 ,"zizo was killed");
        __delay_ms(2000);
        for(counter = 3 ; counter < 18 ; counter++){
            lcd_8bit_send_char_data_pos(&lcd_2, 1 ,counter ,' ');
        }
        __delay_ms(400);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 20 , cross_bar1 , 1);
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 20 , cross_bar2 , 3);
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 19 , cross_bar3 , 4);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 19 , cross_bar4 , 5);
        lcd_8bit_send_custom_char(&lcd_2 , 1 , 1 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 1 , 2 , ball ,0);
        
        
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 5 , zizo , 2);
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 10 , zizo ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 14 , zizo ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 17 , zizo ,2);
        __delay_ms(700);
        lcd_8bit_send_char_data_pos(&lcd_2, 1 ,1 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 1 ,2 ,' ');
        
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 2 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 3 , ball ,0);
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,2 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,3 ,' ');
        
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 3 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 4 , ball ,0);
        
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,3 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,4 ,' ');
        
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 4 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 5 , ball ,0);
        
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 3 ,4 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 3 ,5 ,' ');
        
        for(counter = 5 ; counter < 9 ; counter++){
            lcd_8bit_send_custom_char(&lcd_2 , 3 , counter , messi ,2);
            lcd_8bit_send_custom_char(&lcd_2 , 3 , counter+1 , ball ,0);
            __delay_ms(500);
            lcd_8bit_send_char_data_pos(&lcd_2, 3 ,counter ,' ');
            lcd_8bit_send_char_data_pos(&lcd_2, 3 ,counter+1 ,' ');
        }
        
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 8 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 2 , 9 , ball ,0);
        
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,8 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 2 ,9 ,' ');
        
        for(counter = 9 ; counter < 15 ; counter++){
            lcd_8bit_send_custom_char(&lcd_2 , 2 , counter , messi ,2);
            lcd_8bit_send_custom_char(&lcd_2 , 2 , counter+1 , ball ,0);
            __delay_ms(500);
            lcd_8bit_send_char_data_pos(&lcd_2, 2 ,counter ,' ');
            lcd_8bit_send_char_data_pos(&lcd_2, 2 ,counter+1 ,' ');
        }
        
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 15 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 3 , 16 , ball ,0);
        
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 3 ,15 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 3 ,16 ,' ');
        
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 15 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 16 , ball ,0);
        
        __delay_ms(500);
        lcd_8bit_send_char_data_pos(&lcd_2, 4 ,15 ,' ');
        lcd_8bit_send_char_data_pos(&lcd_2, 4 ,16 ,' ');
        
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 16 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 17 , ball ,0);
        
        __delay_ms(500);
        
        lcd_8bit_send_char_data_pos(&lcd_2, 4 ,17 ,' ');
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 16 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 18 , ball ,0);
        
        __delay_ms(500);
        
        lcd_8bit_send_char_data_pos(&lcd_2, 4 ,18 ,' ');
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 16 , messi ,2);
        lcd_8bit_send_custom_char(&lcd_2 , 4 , 19 , ball ,0);
        
        __delay_ms(500);
        
        lcd_4bit_send_command(&lcd_2 ,_LCD_CLEAR);
        __delay_ms(300);
        lcd_8bit_send_string_pos(&lcd_2 , 2 , 6 ,"messi GooL");
        __delay_ms(800);
        lcd_8bit_send_string_pos(&lcd_2 , 2 , 6 ,"The****End");
        
        
        __delay_ms(2000);
        break;
    }
    return (EXIT_SUCCESS);
}




void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
    
    
}
