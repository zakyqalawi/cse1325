#include <iostream>
#include <string>
#include<fstream>
#include"mandelbrot.h"



int main(int argc, char* argv[]){

int width, height, icount, nthreads;//input_width, input_height, input_icount, input_nthreads;
std::string filename;//input_filename;
filename = "image.ppm";
width =1000;
height = width;
icount =60;
nthreads =1;
/*
if(argv[1]){
width = std::atoi(argv[1]);
    if(argv[2]){
        height = std::atoi(argv[2]);
        if(argv[3]){
            icount = std::atoi(argv[3]);
        
            if(argv[4]){
                nthreads = std::atoi(argv[4]);
                if(argv[5]){
                    filename = argv[5];
             }
           }
        }
    }
}*/
for(int i =0; i<argc; i++){
    if(i==1)width = std::atoi(argv[i]);
    if(i==2) height = std::atoi(argv[i]);
    if(i==3) icount = std::atoi(argv[i]);
    if(i==4) nthreads = std::atoi(argv[i]);
    if(i==5) filename = argv[i];
}
std::cout<<"\nwidth: "<<width<<" height: "<<height<<" icount: "<<icount<<" threads: "<<nthreads<<std::endl;
std::cout<<"wrote: "<<filename<<std::endl;

Mandelbrot m(width, height, icount, nthreads);


std::ofstream oss;
oss.open(filename);
oss<<m;
oss.close();

return 0;
}

/*
std::cout<<"Enter a width: (To skip, press -1)"<<std::endl;
std::cin>>input_width;
if(input_width!=-1) width=input_width;

std::cout<<"Enter a height: (To skip, press -1)"<<std::endl;
std::cin>>input_height;
if(input_height!=-1) height=input_height;

std::cout<<"Enter the number of loops: (To skip, press -1)"<<std::endl;
std::cin>>input_icount;
if(input_icount!=-1) icount=input_icount;

std::cout<<"Enter the number of threads: (To skip, press -1)"<<std::endl;
std::cin>>input_nthreads;
if(input_nthreads!=-1) nthreads=input_nthreads;

std::cout<<"Enter the image file name: (To skip, press -1)"<<std::endl;
std::cin>>input_filename;
if((input_filename.compare("-1"))!= 0) filename=input_filename;
*/
