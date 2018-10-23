        inp
        sta 20
        inp 
        sta 21
        inp 
        sta 22
        lda 23
        add 22
        out
        sta 23
        lda 22
        add 23
        out
        sta 22
        lda 20
        sub 21
        sta 20
        brp 06
        HLT
