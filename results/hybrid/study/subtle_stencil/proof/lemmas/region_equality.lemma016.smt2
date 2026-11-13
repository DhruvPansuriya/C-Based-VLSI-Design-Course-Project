; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x90944 (bvmul arg0_13 arg2_3)))
(let ((?x661510 (bvmul (_ bv4294967295 32) ?x90944)))
(let ((?x108790 (bvmul arg0_13 arg2_4)))
(let ((?x515602 (bvadd ?x108790 ?x661510)))
(and (distinct ?x515602 (_ bv0 32)) true))))))
(check-sat)
