#include "quantum.h"
#include "keymap.h"

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, const combo_t *combo) {
  switch (combo_index) {
    case A_ENT_TO_LCTL_SPC: // a_ent_to_lctl_spc
      return 80; // Custom term for this combo
    default:
      return COMBO_TERM; // Default term for other combos
  }
}
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, const combo_t *combo) {
  switch (combo_index) {
    case A_ENT_TO_LCTL_SPC: // a_ent_to_lctl_spc
      return true; // Custom must tap for this combo
    default:
      return false; // Default must tap for other combos
  }
}
#endif

#ifdef COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
bool get_combo_must_press_in_order(uint16_t combo_index, const combo_t *combo) {
  switch (combo_index) {
    case A_ENT_TO_LCTL_SPC: // a_ent_to_lctl_spc
      return true; // Custom must press in order for this combo
    default:
      return false; // Default must press in order for other combos
  }
}
#endif
