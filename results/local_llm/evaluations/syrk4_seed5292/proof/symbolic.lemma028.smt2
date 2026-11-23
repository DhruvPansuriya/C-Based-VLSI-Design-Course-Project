; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x116 (bvmul arg0_1 arg0_8)))
(let ((?x28780 (bvmul (_ bv4294967295 32) ?x116)))
(let ((?x82 (bvmul arg0_4 arg0_8)))
(let ((?x32175 (bvadd ?x82 ?x28780)))
(and (distinct ?x32175 (_ bv0 32)) true))))))
(check-sat)
