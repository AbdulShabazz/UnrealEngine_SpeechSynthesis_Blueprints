'''rename .mp3 files'''
import os


orig_fn = [
    "ago.EN.mp3",
    "bait.EN.mp3",
    "bat.EN.mp3",
    "batter.EN.mp3",
    "beat.EN.mp3",
    "bet.EN.mp3",
    "bird.EN.mp3",
    "bit.EN.mp3",
    "boat.EN.mp3",
    "Bob.EN.mp3",
    "book.EN.mp3",
    "boot.EN.mp3",
    "bought.EN.mp3",
    "boy.EN.mp3",
    "but.EN.mp3",
    "buy.EN.mp3",
    "cattle.EN.mp3",
    "church.EN.mp3",
    "deep.EN.mp3",
    "down.EN.mp3",
    "five.EN.mp3",
    "go.EN.mp3",
    "help.EN.mp3",
    "just.EN.mp3",
    "kick.EN.mp3",
    "love.EN.mp3",
    "measure.EN.mp3",
    "mom.EN.mp3",
    "noon.EN.mp3",
    "pea.EN.mp3",
    "race.EN.mp3",
    "roses.EN.mp3",
    "show.EN.mp3",
    "sing.EN.mp3",
    "so.EN.mp3",
    "some.EN.mp3",
    "son.EN.mp3",
    "tea.EN.mp3",
    "then.EN.mp3",
    "thing.EN.mp3",
    "vice.EN.mp3",
    "want.EN.mp3",
    "when.EN.mp3",
    "yard.EN.mp3",
    "zebra.EN.mp3"
]

new_fn = [
    "AX._a_go.EN.mp3",
    "EY.b_ait_.EN.mp3",
    "AE.b_a_t.EN.mp3",
    "DX.batter.EN.mp3",
    "IY.b_ea_t.EN.mp3",
    "EH.b_e_t.EN.mp3",
    "ER.b_ir_d.EN.mp3",
    "IH.b_i_t.EN.mp3",
    "OW.b_oa_t.EN.mp3",
    "AA.B_o_b.EN.mp3",
    "UH.b_oo_k.EN.mp3",
    "UW.b_oo_t.EN.mp3",
    "AO.b_ough_t.EN.mp3",
    "OY.b_oy_.EN.mp3",
    "AH.b_u_t.EN.mp3",
    "AY.b_uy_.EN.mp3",
    "EL.catt_le_.EN.mp3",
    "CH._ch_urch.EN.mp3",
    "D._d_eep.EN.mp3",
    "AW.d_ow_n.EN.mp3",
    "F._f_ive.EN.mp3",
    "G._g_o.EN.mp3",
    "HH._h_elp.EN.mp3",
    "JH._j_ust.EN.mp3",
    "K._k_ick.EN.mp3",
    "L._l_ove.EN.mp3",
    "ZH.mea_s_ure.EN.mp3",
    "M._m_om.EN.mp3",
    "N._n_oon.EN.mp3",
    "P._p_ea.EN.mp3",
    "R._r_ace.EN.mp3",
    "IX.ro_s_es.EN.mp3",
    "SH._sh_ow.EN.mp3",
    "NX.sin_g_.EN.mp3",
    "S._s_o.EN.mp3",
    "EM.so_m_e.EN.mp3",
    "EN.so_n_.EN.mp3",
    "T._t_ea.EN.mp3",
    "DH._th_en.EN.mp3",
    "TH._th_ing.EN.mp3",
    "V._v_ice.EN.mp3",
    "W._w_ant.EN.mp3",
    "WH._wh_en.EN.mp3",
    "Y._y_ard.EN.mp3",
    "Z._z_ebra.EN.mp3"
]


def rename_mp3_files():
    '''rename_mp3_files'''
    for i, fn in enumerate(orig_fn):
        nf = new_fn[i]
        try:
            if os.path.isfile(fn):
                os.rename(fn, nf)
                print(f"{fn} => {nf}")
            else:
                # Prefer f-strings over string templates
                print(f"Unable to find file - {fn}.")
        except FileExistsError as e:
            print(f"{fn} - Error - An unexpected error occurred {e}.")


def main():
    '''main'''
    rename_mp3_files()


if __name__ == "__main__":
    main()
