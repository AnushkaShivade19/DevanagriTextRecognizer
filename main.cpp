#include "recognizer.h"
#include <iostream>
#include <map>
#include <opencv2/opencv.hpp>

// Mapping of recognized character labels to their corresponding Devanagari Unicode characters.
inline std::map<std::string, std::string> devanagari_unicode_map = {
    {"character_01_ka", "\u0915"},
    {"character_02_kha", "\u0916"},
    {"character_03_ga", "\u0917"},
    {"character_04_gha", "\u0918"},
    {"character_05_kna", "\u0919"},
    {"character_06_cha", "\u091A"},
    {"character_07_chha", "\u091B"},
    {"character_08_ja", "\u091C"},
    {"character_09_jha", "\u091D"},
    {"character_10_yna", "\u091E"},
    {"character_11_taamatar", "\u091F"},
    {"character_12_thaa", "\u0920"},
    {"character_13_daa", "\u0921"},
    {"character_14_dhaa", "\u0922"},
    {"character_15_adna", "\u0923"},
    {"character_16_tabala", "\u0924"},
    {"character_17_tha", "\u0925"},
    {"character_18_da", "\u0926"},
    {"character_19_dha", "\u0927"},
    {"character_20_na", "\u0928"},
    {"character_21_pa", "\u092A"},
    {"character_22_pha", "\u092B"},
    {"character_23_ba", "\u092C"},
    {"character_24_bha", "\u092D"},
    {"character_25_ma", "\u092E"},
    {"character_26_yaw", "\u092F"},
    {"character_27_ra", "\u0930"},
    {"character_28_la", "\u0932"},
    {"character_29_waw", "\u0935"},
    {"character_30_motosaw", "\u0936"},
    {"character_31_petchiryakha", "\u0937"},
    {"character_32_patalosaw", "\u0938"},
    {"character_33_ha", "\u0939"},
    {"character_34_chhya", "\u0915\u094D\u0937"},
    {"character_35_tra", "\u0924\u094D\u0930"},
    {"character_36_gya", "\u091C\u094D\u091E"},
    {"digit_0", "\u0966"},
    {"digit_1", "\u0967"},
    {"digit_2", "\u0968"},
    {"digit_3", "\u0969"},
    {"digit_4", "\u096A"},
    {"digit_5", "\u096B"},
    {"digit_6", "\u096C"},
    {"digit_7", "\u096D"},
    {"digit_8", "\u096E"},
    {"digit_9", "\u096F"}
};

int main(int argc, char *argv[])
{
    // Ensure the correct number of command-line arguments are provided.
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <dataset_path> <test_image_path> [-l]" << std::endl;
        std::cout << "Optional Argument:\n"
                  << "  -l  Print Recognized Label, instead of Unicode Output\n";
        return -1;
    }

    std::string dataset_path = argv[1];      // Path to dataset
    std::string test_image_path = argv[2];   // Path to test image
    std::string recognized_label = recognize(dataset_path, test_image_path); // Call Student-implemented Method

    // Handle optional argument for display format
    if (argc == 4)
    {
        std::string option = argv[3];
        if (option == "-l")
        {
            std::cout << recognized_label << std::endl; // Print Recognized Label, instead of Unicode Output
        }
        else if (option == "-i")  // Print corresponding Unicode character (used in Interactive Recognizer)
        {
            std::cout << devanagari_unicode_map[recognized_label] << std::endl;
        }
        else
        {
            std::cout << "Invalid argument. Use -l for label output or -i for Devanagari Unicode output." << std::endl;
        }
    }
    else
    {
        // Default Output: Print recognized Devanagari Unicode character
        std::cout << "Recognized Character: " << devanagari_unicode_map[recognized_label] << std::endl;
    }

    return 0;
}
