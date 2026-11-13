; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x191 (bvmul arg0_14 arg1_2)))
(let ((?x11507 (bvmul (_ bv4294967295 32) ?x191)))
(let ((?x116 (bvmul arg0_14 arg1_8)))
(let ((?x15275 (bvadd ?x116 ?x11507)))
(and (distinct ?x15275 (_ bv0 32)) true))))))
(check-sat)
