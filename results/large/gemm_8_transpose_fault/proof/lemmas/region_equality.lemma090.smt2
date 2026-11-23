; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_32 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x33683 (bvmul arg0_8 arg1_32)))
(let ((?x67056 (bvmul (_ bv4294967295 32) ?x33683)))
(let ((?x3538 (bvmul arg0_8 arg1_4)))
(let ((?x54125 (bvadd ?x3538 ?x67056)))
(and (distinct ?x54125 (_ bv0 32)) true))))))
(check-sat)
