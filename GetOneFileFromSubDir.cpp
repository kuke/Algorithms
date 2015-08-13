#include <iostream>
#include <dirent.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    std::string root_dir_name;
    std::string dest;
    if(argc == 3)
    {
        root_dir_name = argv[1]+std::string("/");
        dest = argv[2];
        std::cout<<root_dir_name<<" "<<dest<<std::endl;
    } 
    else
    {
        std::cout<<"Usage: ./Get  <src_dir> <dest_dir>"<<std::endl;
        exit(1);
    }
    DIR *root_dir;
    struct dirent *root_dirp;
    if((root_dir=opendir(root_dir_name.c_str())) == NULL)
    {
        std::cout<<"Err: Open ocl dir failed!\n";
        exit(1);
    }
    while((root_dirp = readdir(root_dir)) != NULL)
    {
        //Ignore hidden files
        if(root_dirp->d_name[0] == '.') continue;
        std::string subdir_name = std::string(root_dirp->d_name);

        std::string subdir_full_name=root_dir_name+subdir_name;
        std::cout<<subdir_full_name<<std::endl;
        struct dirent *subdir_dirp;
        DIR *subdir_dir;
    	if((subdir_dir=opendir(subdir_full_name.c_str())) == NULL)
    	{
            continue; 
   	}

        while((subdir_dirp=readdir(subdir_dir)) != NULL)
        { 
            if(subdir_dirp->d_name[0] == '.') continue;
            std::string file_name = subdir_dirp->d_name;
            std::string file_full_name = subdir_full_name+"/"+file_name;
            std::string copy_cmd = "cp "+file_full_name+" "+dest;
            system(copy_cmd.c_str());
            break;
   	}
    }


    return 0;
}

