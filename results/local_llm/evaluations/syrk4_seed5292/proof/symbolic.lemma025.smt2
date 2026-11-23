; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x965 (bvmul arg0_10 arg0_8)))
(let ((?x20506 (bvmul (_ bv4294967295 32) ?x965)))
(let ((?x1095 (bvmul arg0_10 arg0_2)))
(let ((?x25210 (bvadd ?x1095 ?x20506)))
(and (distinct ?x25210 (_ bv0 32)) true))))))
(check-sat)
