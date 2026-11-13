; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x51 (bvmul arg0_12 arg1_8)))
(let ((?x12036 (bvmul (_ bv4294967295 32) ?x51)))
(let ((?x182 (bvmul arg0_12 arg1_2)))
(let ((?x20507 (bvadd ?x182 ?x12036)))
(and (distinct ?x20507 (_ bv0 32)) true))))))
(check-sat)
