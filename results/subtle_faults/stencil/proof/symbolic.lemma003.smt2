; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x235 (bvmul arg0_6 arg2_3)))
(let ((?x166 (bvmul (_ bv4294967295 32) ?x235)))
(let ((?x5942 (bvmul arg0_6 arg2_4)))
(let ((?x723951 (bvadd ?x5942 ?x166)))
(and (distinct ?x723951 (_ bv0 32)) true))))))
(check-sat)
