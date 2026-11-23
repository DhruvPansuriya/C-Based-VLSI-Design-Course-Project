; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x576902 (bvmul arg0_13 arg1_1)))
(let ((?x563690 (bvmul (_ bv4294967295 32) ?x576902)))
(let ((?x508983 (bvmul arg0_13 arg1_4)))
(let ((?x310674 (bvadd ?x508983 ?x563690)))
(and (distinct ?x310674 (_ bv0 32)) true))))))
(check-sat)
