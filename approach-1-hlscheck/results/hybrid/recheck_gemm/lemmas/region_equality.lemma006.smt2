; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x146 (bvmul arg0_3 arg1_7)))
(let ((?x228 (bvmul (_ bv4294967295 32) ?x146)))
(let ((?x60 (bvmul arg0_3 arg1_13)))
(let ((?x3572 (bvadd ?x60 ?x228)))
(and (distinct ?x3572 (_ bv0 32)) true))))))
(check-sat)
