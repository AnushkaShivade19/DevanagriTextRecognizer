#include "recognizer.h"
#include <iostream>
#include <map>

inline std::map<std::string, std::string> devanagari_unicode_map = {
    {"character_01_ka", u8"\u0915"},
    {"character_02_kha", u8"\u0916"},
    {"character_03_ga", u8"\u0917"},
    {"character_04_gha", u8"\u0918"},
    {"character_05_kna", u8"\u0919"},
    {"character_06_cha", u8"\u091A"},
    {"character_07_chha", u8"\u091B"},
    {"character_08_ja", u8"\u091C"},
    {"character_09_jha", u8"\u091D"},
    {"character_10_yna", u8"\u091E"},
    {"character_11_taamatar", u8"\u091F"},
    {"character_12_thaa", u8"\u0920"},
    {"character_13_daa", u8"\u0921"},
    {"character_14_dhaa", u8"\u0922"},
    {"character_15_adna", u8"\u0923"},
    {"character_16_tabala", u8"\u0924"},
    {"character_17_tha", u8"\u0925"},
    {"character_18_da", u8"\u0926"},
    {"character_19_dha", u8"\u0927"},
    {"character_20_na", u8"\u0928"},
    {"character_21_pa", u8"\u092A"},
    {"character_22_pha", u8"\u092B"},
    {"character_23_ba", u8"\u092C"},
    {"character_24_bha", u8"\u092D"},
    {"character_25_ma", u8"\u092E"},
    {"character_26_yaw", u8"\u092F"},
    {"character_27_ra", u8"\u0930"},
    {"character_28_la", u8"\u0932"},
    {"character_29_waw", u8"\u0935"},
    {"character_30_motosaw", u8"\u0936"},
    {"character_31_petchiryakha", u8"\u0937"},
    {"character_32_patalosaw", u8"\u0938"},
    {"character_33_ha", u8"\u0939"},
    {"character_34_chhya", u8"\u0915\u094D\u0937"},
    {"character_35_tra", u8"\u0924\u094D\u0930"},
    {"character_36_gya", u8"\u091C\u094D\u091E"},
    {"digit_0", u8"\u0966"},
    {"digit_1", u8"\u0967"},
    {"digit_2", u8"\u0968"},
    {"digit_3", u8"\u0969"},
    {"digit_4", u8"\u096A"},
    {"digit_5", u8"\u096B"},
    {"digit_6", u8"\u096C"},
    {"digit_7", u8"\u096D"},
    {"digit_8", u8"\u096E"},
    {"digit_9", u8"\u096F"}
};

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <dataset_path> <test_image_path> [-l|-i]\n";
        std::cout << "  -l : print recognized label (directory name)\n";
        std::cout << "  -i : print Devanagari unicode char\n";
        return -1;
    }

    std::string dataset_path = argv[1];
    std::string test_image_path = argv[2];

    std::string recognized_label = recognize(dataset_path, test_image_path);

    if (recognized_label.empty()) {
        std::cout << "No match found or could not read test image.\n";
        return 0;
    }

    if (argc == 4) {
        std::string option = argv[3];
        if (option == "-l") {
            std::cout << recognized_label << std::endl;
        } else if (option == "-i") {
            auto it = devanagari_unicode_map.find(recognized_label);
            if (it != devanagari_unicode_map.end()) std::cout << it->second << std::endl;
            else std::cout << "Unicode mapping not found for label: " << recognized_label << std::endl;
        } else {
            std::cout << "Unknown option. Use -l or -i\n";
        }
    } else {
        auto it = devanagari_unicode_map.find(recognized_label);
        if (it != devanagari_unicode_map.end()) std::cout << "Recognized: " << it->second << std::endl;
        else std::cout << "Recognized label: " << recognized_label << " (no unicode mapping)\n";
    }

    return 0;
}
