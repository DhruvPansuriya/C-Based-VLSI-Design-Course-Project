; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x12966 (bvmul arg0_11 arg1_14)))
(let ((?x55228 (bvmul (_ bv4294967295 32) ?x12966)))
(let ((?x22849 (bvmul arg0_11 arg1_15)))
(let ((?x398603 (bvadd ?x22849 ?x55228)))
(and (distinct ?x398603 (_ bv0 32)) true))))))
(check-sat)
