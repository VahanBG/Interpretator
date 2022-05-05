#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include<string>

struct variable{
    std::string type;
    std::string value;
};

std::vector< std::string> keywords{"num", "fnum", "logic", "if", "while", "print" };
std::map<std::string, variable> var_info;
 
int is_keyword_index (std::string first_token)
 {
    
    for (int i = 0; i < keywords.size(); i++)
    {
        if(keywords[i] == first_token){ return i;}
        
    }        
     return -1;
}
void do_decleration_for_logic (std::ifstream& fin,int type_index)
{
    std::string token;
    do
    {
           //std::cout<<type_index;
        std::string name;
        fin >> token;
        var_info[token].type = keywords[type_index];
        keywords.push_back(token);
        name = token;  
            
       //std::cout<<var_info[token].type;
        fin >> token;
        if(token == "=")
        {
            fin >> token;
            if(token == "!")
            { 
                fin>>token;
                for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 else{var_info[name].value = token;}
                 }
                std::string tmp;
                fin>>tmp;
                if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
                {
                char tmp1=tmp[0]; 
                bool num;
                int num1,num2;  
                std::string tmp_next;
                std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 > num2); 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1<num2); 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1&&num2); 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1||num2); 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1==num2); 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break; 
                }
                }  
                if((tmp ==">=")||(tmp == "<="))
                {
                char tmp1=tmp[0]; 
                bool num;
                int num1,num2;  
                std::string tmp_next;
                std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 >= num2); 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num =!( num1 <= num2); 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;   
                
                }                
                  
                }

                fin >> token;
                //std::cout<<token<<std::endl;
             }
            else
            {
                for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 else{var_info[name].value = token;}
                 }   
            std::string tmp; 
            fin >> tmp;
            if(tmp == ";")
            {
                   if(token == "1")
                     {
                          var_info[name].value = token;
                          token = tmp ;
                     }

                   if(token == "0")
                     {
                          var_info[name].value = token;
                          token = tmp ;
                     }
            }
            if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 > num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1<num2; 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1&&num2; 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1||num2; 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = (num1 == num2); 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break; 
                }
            }  
            if((tmp ==">=")||(tmp == "<="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 >= num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 <= num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;   
                
                }                

            }
       }
            fin >> token;
     std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
                       
        }
     // if((token == ";")&&(tpm123 == "=")){ var_info[name].value = "0" ;}
       //           std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
    }
        
    
   
    while(token != ";");
}
void do_decleration_for_num (std::ifstream& fin,int type_index)
{
    std::string token;
    do
      {
        std::string name;

        fin >> token;     
       // std::cout<<token<<std::endl;  
        // if (is_identifier(token))
        var_info[token].type = keywords[type_index];
        keywords.push_back(token);
        name = token;  
            
              //std::cout<<keywords[type_index];
              fin >> token;
                 if(token == "=")
                 {
                 fin >> token;// 5 i vra e
                 for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 else{var_info[name].value = token;}
                 }
                 std::string tmp; // + i vra e
                 fin >> tmp;
                                       
                    if((tmp=="+")||(tmp=="-")||(tmp=="*")||(tmp=="/"))
                     {
                     char tmp1=tmp[0]; 
                     int num,num1,num2;  
                     std::string tmp_next;
                     std::string vol="";         
                         switch(tmp1)
                          {
                          case '+': 
                          fin>>tmp_next; 
                          for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                          num1 = std::stoi(token);
                          num2 = std::stoi(tmp_next);
                          num = num1+num2; 
                          vol=std::to_string(num);
                          var_info[name].value = vol;
                          break;
                          case '-':
                          fin>>tmp_next; 
                          for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                          num1 = stoi(token);
                          num2 = stoi(tmp_next);
                          num = num1-num2; 
                          vol=std::to_string(num);
                          var_info[name].value =vol;
                          break;
                          case '*':
                          fin>>tmp_next; 
                          for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                          num1 = stoi(token);
                          num2 = stoi(tmp_next);
                          num = num1*num2; 
                          vol=std::to_string(num);
                          var_info[name].value = vol;
                          break; 
                          case '/':
                          for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                          fin>>tmp_next; 
                          num1 = stoi(token);
                          num2 = stoi(tmp_next);
                          num = num1/num2; 
                          vol=std::to_string(num);
                          var_info[name].value = vol;
                          break;  
                          } //switch
                          } // if + - 
                          if (tmp == ";"){var_info[name].value = token;token = tmp ;}
                           fin >> token; 
                           std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
               
                     
                 
                 }// if ==
                // if(token == ";"){ var_info[name].value = "0" ;}
                  //std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
       } //do
             while(token!= ";");
} //funqcia
void do_decleration_for_fnum (std::ifstream& fin,int type_index)

{
    std::string token;
    do
    {
        std::string name;
        fin >> token;        
        // if (is_identifier(token))
        var_info[token].type = keywords[type_index];
        keywords.push_back(token);
        name = token;        
        //std::cout<<var_info[token].type;
        fin >> token;
        if(token == "=")
       {
            fin >> token;// 5 i vra e
             for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 else{var_info[name].value = token;}
                 }
            var_info[name].value = token;
            std::string tmp; // + i vra e
            fin >> tmp;
                     
            if((tmp=="+")||(tmp=="-")||(tmp=="*")||(tmp=="/"))
            {
            char tmp1=tmp[0]; 
            double num,num1,num2;  
            std::string tmp_next;
            std::string vol="";         
            switch(tmp1)
            {
            case '+': 
                       fin>>tmp_next; // 6 -i vra e<
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = std::stod(token);
                       num2 = std::stod(tmp_next);
                       num = num1+num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;
            case '-':
                       
                       fin>>tmp_next; // 6 -i vra e
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = std::stod(token);
                       num2 = std::stod(tmp_next);
                       num = num1-num2; 
                       vol=std::to_string(num);
                       var_info[name].value =vol;
                       break;
            case '*':
                   
                       fin>>tmp_next; // 6 -i vra e
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = std::stod(token);
                       num2 = std::stod(tmp_next);
                       num = num1*num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break; 
            case '/':
                   
                       fin>>tmp_next; // 6 -i vra e
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           else{var_info[name].value = tmp_next;}
                           }
                       num1 = std::stod(token);
                       num2 = std::stod(tmp_next);
                       num = num1/num2; 
                       vol=std::to_string(num);
                       var_info[name].value = vol;
                       break;  
               } // swich 
            }  // + - * / 
             if (tmp == ";"){var_info[name].value = token;token = tmp ;}
                  fin >> token;
             std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
       }        // if  =
      // if(token == ";"){ var_info[name].value = "0" ;}
        //          std::cout<<"type of "<<name<<" is "<<keywords[type_index]<<" value is : "<<var_info[name].value<<std::endl;
    }//do
    while(token!=";");
}
void do_decleration_for_if (std::ifstream& fin,int type_index)
{
        std::string token;
        bool cheek;
        
do{
         bool if_cond_value;
        
         fin >> token;
        // std::cout<<token<<"box"<<std::endl;
         if(token != "("){std::cout<<"your loop writen wrong"<<std::endl;}
         else
         {
                fin >>token;// popoxakani vra e
                 if(token == "!")
            {
                   fin >>token;
                   for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 }
                 
                 std::string tmp; 
            fin >> tmp;            
            if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !( num1 > num2); 
                       if_cond_value=num;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1<num2); 
                       if_cond_value=num;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1&&num2); 
                       if_cond_value=num;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1||num2); 
                       if_cond_value=num;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 == num2); 
                       if_cond_value=num;
                       break; 
                }
            }  
            if((tmp ==">=")||(tmp == "<="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 >= num2); 
                       if_cond_value=num;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 <= num2); 
                       if_cond_value=num;
                       break;   
                  }                
             } 
              
             fin >> token;
             //std::cout<<token; 
            }
            else{
             
                 for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 }
                 std::string tmp; 
            fin >> tmp;            
            if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 > num2; 
                       if_cond_value=num;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1<num2; 
                       if_cond_value=num;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1&&num2; 
                       if_cond_value=num;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1||num2; 
                       if_cond_value=num;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = (num1 == num2); 
                       if_cond_value=num;
                       break; 
                }
            }  
            if((tmp ==">=")||(tmp == "<="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 >= num2; 
                       if_cond_value=num;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 <= num2; 
                       if_cond_value=num;
                       break;   
                  }                
             } 
            }//Else      
          } //else
          //std::cout<<if_cond_value<<std::endl;
          fin >> token;
          cheek= if_cond_value;
        //  std::cout<<token<< "barev"<<std::endl;
}//do
while(token != ")");
}
void do_decleration_for_while (std::ifstream& fin,int type_index)
{
        std::string token;
        
do{
         bool if_cond_value;
         fin >> token;
        // std::cout<<token<<"box"<<std::endl;
         if(token != "("){std::cout<<"your if writen wrong"<<std::endl;}
         else
         {
                fin >>token;// popoxakani vra e
                 if(token == "!")
            {
                   fin >>token;
                   for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 }
                 
                 std::string tmp; 
            fin >> tmp;            
            if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !( num1 > num2); 
                       if_cond_value=num;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1<num2); 
                       if_cond_value=num;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1&&num2); 
                       if_cond_value=num;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1||num2); 
                       if_cond_value=num;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 == num2); 
                       if_cond_value=num;
                       break; 
                }
            }  
            if((tmp ==">=")||(tmp == "<="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 >= num2); 
                       if_cond_value=num;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = !(num1 <= num2); 
                       if_cond_value=num;
                       break;   
                  }                
             } 
              
             fin >> token;
             //std::cout<<token; 
            }
            else{
             
                 for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i]){token= var_info[keywords[i]].value;}
                        
                 }
                 std::string tmp; 
            fin >> tmp;            
            if((tmp==">")||(tmp=="<")||(tmp=="&&")||(tmp=="||")||(tmp =="=="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 > num2; 
                       if_cond_value=num;
                       break;
                case '<':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1<num2; 
                       if_cond_value=num;
                       break;
                case '&':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1&&num2; 
                       if_cond_value=num;
                       break;
                case '|':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1||num2; 
                       if_cond_value=num;
                       break; 
                case '=':
                       
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = (num1 == num2); 
                       if_cond_value=num;
                       break; 
                }
            }  
            if((tmp ==">=")||(tmp == "<="))
            {
            char tmp1=tmp[0]; 
            bool num;
            int num1,num2;  
            std::string tmp_next;
            std::string vol="";         
                switch(tmp1)
                {
                case '>': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                           
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 >= num2; 
                       if_cond_value=num;
                       break;
                case '<': 
                       fin>>tmp_next; 
                       for (int i = 0; i < keywords.size(); i++)
                          {
                           if (tmp_next == keywords[i]){tmp_next= var_info[keywords[i]].value;}
                          
                           }
                       num1 = stoi(token);
                       num2 = stoi(tmp_next);
                       num = num1 <= num2; 
                       if_cond_value=num;
                       break;   
                  }                
             } 
            }//Else      
          } //else
          //std::cout<<if_cond_value<<std::endl;
          fin >> token;
         // std::cout<<token<< "barev"<<std::endl;
}//do
while(token != ")");
}
void print(std::ifstream &fin ,int type_index)
{
      // std::cout<<type_index<<std::endl;
    std::string token;
     do
      { 
             fin >> token; 
             //std::cout<<token<<std::endl;
                  for (int i = 0; i < keywords.size(); i++)
                 {
                        if (token == keywords[i])
                        {
                        token= var_info[keywords[i]].value;

                        }
                 } 
                 std::cout<< token <<std::endl;
              
              fin>>token ;
                    }
      while(token != ";" );
} 
void do_interpretation (std::ifstream& fin){
    std::string token="";
    while (!fin.eof())
    {
           
        fin >> token;

          // std::cout << token << std::endl;
        int case_ind = is_keyword_index(token);
        switch (case_ind)
        {
       
        case 0:do_decleration_for_num (fin, case_ind);
               break;
        case 1:do_decleration_for_fnum (fin, case_ind);
               break;
        case 2:
                do_decleration_for_logic(fin, case_ind);
                break; 
        case 3:
                 do_decleration_for_if (fin, case_ind);
                 break;
        case 4:
                do_decleration_for_while (fin, case_ind);
                break;
        case 5:
                print(fin , case_ind);
                break; 
        case -1: 
               std::cout << "You have a error" << std::endl;
                break;
        //default:
                // do_operation();
                // break;
        }

    }
}

int main()
{
    std::ifstream file;
    std::string path="test.txt";
    int type_index=0;
    file.open(path);
    std::string token,tmp;
    if(file.is_open())
    {
        std::cout<<"The file you selected was successfully uploaded"<<std::endl;
        do_interpretation(file);
    }
    else
    {
        std::cout << "Something was gone wrong" << std::endl;
    }
      
return 0;
}