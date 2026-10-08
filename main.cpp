#include <libndls.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void _fini(void) {}

int main() {
    assert_ndless_rev(45);

    console_init();

    printf("========================================\n");
    printf("   TI-NSPIRE SYSTEM CONTROL CENTER      \n");
    printf("========================================\n\n");

    printf("[ HARDWARE READOUT ]\n");
    printf(" Ndless Revision : %d\n", ndless_rev());
    printf(" Hardware Model  : %s\n", hw_type() == 0 ? "Classic" : (hw_type() == 1 ? "CX" : "CX II"));
    printf(" Battery Level   : %d%%\n", battery_level());
    printf(" Charging Status : %s\n\n", is_charging() ? "Charging" : "Discharging");

    printf("[ SYSTEM STATUS ]\n");
    printf(" Clock Frequency : Normal (ARM)\n");
    printf(" Keypad Status   : Active\n\n");

    printf("========================================\n");
    printf(" Press [ESC] to exit\n");
    printf("========================================\n");

    while (!isKeyPressed(KEY_NSPIRE_ESC)) {
        msleep(50);
    }

    console_disp();
    return 0;
}
