#ifndef CartPoleTestEnv_cpp
#define CartPoleTestEnv_cpp

#include "./../include/reactive.hpp"

void strip(std::string &s) {
    while(s.size()>0 && (s[s.size()-1]=='\n' || s[s.size()-1]=='\r'))
        s = s.substr(0, s.size()-1);
}

void interaction() {
    for(;;) {
        std::string line = reactive_read();
        strip(line);
        if(line.empty()) {
            return;
        }
        if(line[0]!='r' && line[0]!='s' && line[0]!='q') {
            return;
        }

        if(line[0] == 'r') {

            reactive_write("obs "+std::to_string(1.0) + " " + std::to_string(2.0) + " " + std::to_string(3.0) + " " + std::to_string(4.0) + "\n");
            continue;
        } else if (line[0] == 's'){

            reactive_write("obs "+std::to_string(1.0) + " " + std::to_string(2.0) + " " + std::to_string(3.0) + " " + std::to_string(4.0) + "\n");

        } else if (line[0] == 'q') {
            return;
        }
    }
}

int main(int argc,char **argv) {
    reactive_start(argv[1]);
    interaction();
    reactive_end();
    return 0;
}

#endif /* CartPoleTestEnv_cpp */
