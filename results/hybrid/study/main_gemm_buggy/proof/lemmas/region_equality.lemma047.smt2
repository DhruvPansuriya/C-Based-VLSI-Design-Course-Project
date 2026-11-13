; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x3023 (bvmul arg0_13 arg1_13)))
(let ((?x17021 (bvmul (_ bv4294967295 32) ?x3023)))
(let ((?x46 (bvmul arg0_13 arg1_7)))
(let ((?x7722 (bvadd ?x46 ?x17021)))
(and (distinct ?x7722 (_ bv0 32)) true))))))
(check-sat)
