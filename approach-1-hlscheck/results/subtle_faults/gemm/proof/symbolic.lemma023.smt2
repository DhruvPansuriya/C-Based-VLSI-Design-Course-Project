; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x156 (bvmul arg0_5 arg1_13)))
(let ((?x12786 (bvmul (_ bv4294967295 32) ?x156)))
(let ((?x15 (bvmul arg0_5 arg1_7)))
(let ((?x3769 (bvadd ?x15 ?x12786)))
(and (distinct ?x3769 (_ bv0 32)) true))))))
(check-sat)
