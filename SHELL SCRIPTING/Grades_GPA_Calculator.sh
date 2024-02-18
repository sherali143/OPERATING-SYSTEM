#! /bin/bash
# SIR I AM SUPPOSING 3 SUBJECT AND CALCULATING ON THE BASIS OF THESE SUBJECT .

calculate()
{
    echo "Enter the Subject1 marks"
    read sub1

    echo "Enter the Subject2 marks"
    read sub2

    echo "Enter the Subject3 marks"
    read sub3

    marks=0

    marks=$((sub1 + sub2 + sub3 ))
    
    average=$((marks/3))

    echo "Marks is : $marks"
    echo "average is : $average"

    if [ $average -gt 85 ];then
        echo "Your grade is : A" 
        echo "Your GPA is : 4"

    elif [ $average -gt 80 ] && [ $average -lt 85 ];then
            echo "Your grade is : A-" 
            echo "Your GPA is :3.66"                                                                                                
   
    elif [ $average -gt 75 ] && [ $average -lt 80 ];then
            echo "Your grade is : B+"
            echo "Your GPA is : 3.33"
                                                                                                         
    elif [ $average -gt 70 ] && [ $average -lt 75 ];then
            echo "Your grade is : B"
            echo "Your GPA is : 3"
                                                                                                         
    elif [ $average -gt 65 ] && [ $average -lt 70 ];then
            echo "Your grade is : B-"
            echo "Your GPA is : 2.66"                                                                                           
    
    elif [ $average -gt 60 ] && [ $average -lt 65 ];then
            echo "Your grade is : C+"
            echo "Your GPA is : 2.33"
    elif [ $average -gt 55 ] && [ $average -lt 60 ];then
            echo "Your grade is : C-"
            echo "Your GPA is : 2"                                                                                                
    elif [ $average -gt 50 ] && [ $average -lt 55 ];then
            echo "Your grade is : D"                                                                                                    
            echo "Your GPA is : 1"
    else
        echo "Your Grade is F"
  
    fi

   

    
    

    
}

calculate 
exit 0;


