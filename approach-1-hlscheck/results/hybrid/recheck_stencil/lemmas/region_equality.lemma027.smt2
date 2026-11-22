; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x105 (bvmul arg0_23 arg2_8)))
(let ((?x336710 (bvmul (_ bv4294967295 32) ?x105)))
(let ((?x8852 (bvmul arg0_23 arg2_7)))
(let ((?x112089 (bvadd ?x8852 ?x336710)))
(and (distinct ?x112089 (_ bv0 32)) true))))))
(check-sat)
